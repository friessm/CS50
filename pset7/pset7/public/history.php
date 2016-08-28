<?php

    require("../includes/config.php");
    
    // fill array with history of user's share transactions
    $rows = CS50::query("SELECT type, symbol, shares, price_trans, date FROM history WHERE user_id = ?", $_SESSION["id"]);
    
    render("history_form.php", ["Title" => "History", "symbols" => $rows]);
    
?>
