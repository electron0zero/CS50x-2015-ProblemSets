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
<form action="buy.php" method="post">
    <fieldset>
        <div class="form-group">
            <input autofocus name="code" placeholder="Stock symbol(exapmle: GOOG,AAPL etc)" type="text"/>
        </div>
        <div class="form-group">
            <input name="shares" placeholder="No of Shares" type="text"/>
        </div>
        <div class="form-group">
            <button type="submit" class="btn">Buy Stock</button>
        </div>
    </fieldset>
</form>
