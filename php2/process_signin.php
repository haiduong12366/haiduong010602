<?php 

$email = $_POST['email'];
$password = $_POST['password'];

require 'admin/connect.php';

$sql = "select * from customers
where email = '$email' and password = '$password'";
$result  = mysqli_query($connect,$sql);
$number_row = mysqli_num_rows($result);
if(isset($_POST['remember']))
{
    $remember = true;
}
else
    $remember = false;
if($number_row == 1)
{
    echo 'Đăng nhập thành công';
    session_start();
    $each = mysqli_fetch_array($result);
    $id = $each['id'];
    $_SESSION['id'] = $each['id'];
    $_SESSION['name'] = $each['name'];
    if($remember)
    {
        $token = uniqid('user_',true);
        $sql = "update customers
        set
        token = '$token'
        where
        id = $id";
        mysqli_query($connect,$sql);
        setcookie('remember',$token,time()+60*60*24*30);
    }
    
    header('location:user.php');
    exit;
}
header("location:signin.php?error=Sai tài khoản hoặc mật khẩu");
exit;
