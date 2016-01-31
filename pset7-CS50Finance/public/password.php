<?php
    // configuration
require("../includes/config.php");
//for showing username in password reset from
$name = query("SELECT username FROM users WHERE id = ?", $_SESSION["id"]);

// if form was submitted
if ($_SERVER["REQUEST_METHOD"] == "POST")
{           
      print_r($_POST);      
            
            $rows = query("SELECT * FROM users WHERE id = ?", $_SESSION["id"]);
            $row = $rows[0];
             
        // validate submission
        
        if (crypt($_POST["oldpassword"], $row["hash"]) != $row["hash"])
        {
            apologize("Old Password was not correct.");
        }
        
        if ($_POST["password"] != $_POST["confirmation"])
        {
         apologize("new password does not match its Confirmation.");
        }
                
        else
        {   //when we able to write new password in db sucessfully then redirect user
         if(query("UPDATE users SET hash = ( ? ) WHERE id = ( ? )", crypt($_POST["password"]),$_SESSION["id"]) === false)
         {
           apologize("Sorry, some internal error occurred.");
         } else {   
                    redirect("index.php");
                }
        }
        
        
}  
else
{   
    
    // else render form
    render("password-change.php", ["title" => "Change Password","name" => $name ]);
}
?>
