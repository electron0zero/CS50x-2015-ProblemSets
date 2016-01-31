<div id = "nav-bar">
    <ul class="nav nav-pills">
    <li><a href="index.php">Portfolio</a></li>
    <li><a href="quote.php">Quote</a></li>
    <li><a href="buy.php">Buy</a></li>
    <li><a href="sell.php">Sell</a></li>
    <li><a href="history.php">History</a></li>
    <li><a href="password.php">change password</a></li>    
    <li><a href="logout.php"><strong>Log Out</strong></a></li>
    </ul>
    </div>
<form action="password.php" method="post">
     
           <!-- getting username via render function argument and printing username -->
            <h2><strong><?=$name[0]["username"]?></strong></h2>
         
    <fieldset>                   
        <div class="form-group">
            <input autofocus name="oldpassword" placeholder="Old Password" type="password"/>
        </div>
        <div class="form-group">
            <input name="password" placeholder="New Password" type="password"/>
       </div>
        <div class="form-group">
            <input name="confirmation" placeholder="Confirmation" type="password"/>
         </div>
        <div class="form-group">
            <button type="submit" class="btn">Chage Password!</button>
         </div>
    </fieldset>
</form>
