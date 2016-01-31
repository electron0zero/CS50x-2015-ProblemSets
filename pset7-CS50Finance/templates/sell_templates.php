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
<form action="sell.php" method="post">
    <fieldset>
        <div class="control-group">
            <select name="code">
                <option value='-------'>-------</option>
                <?php
                    foreach($symbols as $symbol)
                    {
                        print("<option value='{$symbol["symbol"]}'>{$symbol["symbol"]}</option>\n");
                    }
                ?>
            </select>
        </div>
        <div class="control-group">
            <button type="submit" class="btn">Sell</button>
        </div>
    </fieldset>
</form>
