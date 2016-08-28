<?php

    require(__DIR__ . "/../includes/config.php");

    // ensure proper usage
    if (empty($_GET["geo"]))
    {
        http_response_code(400);
        exit;
    }

    // get geography's articles
    $articles = lookup($_GET["geo"]);
    
    // supress error messages so the json returned is without 'xdebug-error xe-warning' error lines
    error_reporting(0);
    
    // output articles as JSON (pretty-printed for debugging convenience)
    header("Content-type: application/json");
    print(json_encode($articles, JSON_PRETTY_PRINT));

?>