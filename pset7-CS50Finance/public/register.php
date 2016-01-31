<?php

    // configuration
    require("../includes/config.php");

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("register_form.php", ["title" => "Register"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // TODO
        //form validation
        if(empty($_POST["username"]))
        {
        apologize("you must provide username");
        }
        else if(empty($_POST["password"]))
        {
        apologize("you must provide password");
        }
        else if(empty($_POST["confirmation"]))
        {
        apologize("you must retype your password to confirm your password");
        }
        else if(($_POST["confirmation"])!=($_POST["password"]))
        {
        apologize("password and confirmation password must be same");
        }
        //have fun with db
        //check if username is already there
        $usertest = query( "SELECT * FROM users WHERE username = ?", $_POST["username"] );
        
        if(count($usertest)==1){ //username already exists
        
        apologize("username already exists");
        }
        else    //insrt user into DB
        {
        query("INSERT INTO users (username, hash, cash) VALUES(?, ?, 10000.00)", $_POST["username"], crypt($_POST["password"]));
            
            //confirm that user is sucessfully registered and log user in after registration.
            if($query === false ){
            apologize("registration failed");
            }
            else
            {
            //get the id and log user in
            $rows = query("SELECT LAST_INSERT_ID() AS id");
            //check that we got id
            if(count($rows)==1){
                $id=$rows[0]["id"];
                $_SESSION["id"]=$id;
                
                //remember username and redirect user to profile
                $_SESSION["username"]=$row["username"];
                $_SESSION["cash"]=$row["cash"];
                
                //redirect to index.php
                redirect("/index.php");
                
                }
          
            }
        }
        
        
    }
    else
    {   
          render("register_form.php",["title"=>"Register"]);
    }

?>
