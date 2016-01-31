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
<table class="table table-hover">
    <thead>
        <tr>
            <th>Action</th>
            <th>Symbol</th>
            <th>Shares</th>
            <th>Price</th>
            <th>Date</th>
        </tr>
    </thead>
    <tbody>
        <?php foreach($history as $record): ?>
            <tr>
                <td><?=$record["action"] ?></td>
                <td><?=$record["symbol"] ?></td>
                <td><?=$record["shares"] ?></td>
                <td><?=number_format($record["price"], 2) ?></td>
                
                <td><?= date('Y-m-d H:i:s', strtotime($record["date"])) ?></td>
            </tr>
        <?php endforeach ?>
    </tbody>
</table>
