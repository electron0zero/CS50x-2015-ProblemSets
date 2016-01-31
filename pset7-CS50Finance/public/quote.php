<?php

    // configuration
    require("../includes/config.php");

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("quote_form.php",["title"=>"Get Quote"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // TODO
       //form validation
       if(empty($_POST["symbol"]))
        {
        apologize("you must provide Symbol");
        }
       //do a lookup
       $stock = lookup($_POST["symbol"]);
       //validte symbol name 
       if($stock == false)
        {   //if symbol is invalid apologize
        apologize("invalid Symbol Name !!! please enter a valid symbol");
        }   //else get quote and render it
       else
       {
       render("quote_result.php",["title"=>"Quote","name"=>$stock["name"],"symbol"=>$stock["symbol"],"price"=>$stock["price"]]);
       }
          
    }
    else
    {   
          render("quote_form.php",["title"=>"Get Quote"]);
    }

?>
