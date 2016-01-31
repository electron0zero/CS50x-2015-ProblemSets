<?php
    // configuration
    require("../includes/config.php");
    
    // Query current users shares
    $rows = query("SELECT symbol, shares, price FROM shares WHERE id = ?", $_SESSION["id"]);
    $user = query("SELECT username,cash FROM users WHERE id = ?", $_SESSION["id"]);
    
    // Construnct the view
    $shares = [];
    
    foreach($rows as $row)
    {
        // Query the Yahoo
        $stock = lookup($row["symbol"]);
        
        if ($stock !== false)   //if we get data from yahoo
        {
            $shares[] = [
                "symbol"    => $row["symbol"]
                ,"name"     => $stock["name"]
                ,"shares"   => $row["shares"]
                ,"price_bought" => $row["price"]
                ,"price_cur"    => $stock["price"]
                ,"total_bought" => $row["shares"] * $row["price"]
                ,"total_cur"    => $row["shares"] * $stock["price"]
                ,"profit"   => $row["shares"] * $stock["price"] - $row["shares"] * $row["price"]               
            ];
        }
    }
//printf debug
//print_r($_SESSION);
//print_r($user[0]);

    // render portfolio
    render("portfolio.php", ["title" => "Portfolio", "user" => $user , "shares" => $shares]);

?>
