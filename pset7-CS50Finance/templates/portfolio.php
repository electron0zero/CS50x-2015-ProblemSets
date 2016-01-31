
<div>
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
<p>
Welcome back, <strong><?=$user[0]["username"]?>!</strong> Your current deposit is <strong>$<?=number_format($user[0]["cash"], 2)?></strong>
</p>

<table class="table table-hover">
    <thead>
        <tr>
            <th>Symbol</th>
            <th>Name</th>
            <th>Shares</th>
            <th>Price Bought</th>
            <th>Price Current</th>
            <th>Total Bought</th>
            <th>Total Current</th>
            <th>Total gains / losses</th>
        </tr>
    </thead>
    <tbody>
        <?php foreach($shares as $share): ?>
            <tr>
                <td><?=$share["symbol"] ?></td>
                <td><?=$share["name"] ?></td>
                <td><?=$share["shares"] ?></td>
                <td><?=number_format($share["price_bought"], 2) ?></td>
                <td><?=number_format($share["price_cur"], 2) ?></td>
                <td><?=number_format($share["total_bought"], 2) ?></td>
                <td><?=number_format($share["total_cur"], 2) ?></td>
                <td><?=number_format($share["profit"], 2) ?></td>
            </tr>
        <?php endforeach ?>
    </tbody>
</table>
</div>
