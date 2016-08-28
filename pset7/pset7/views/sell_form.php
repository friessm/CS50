
<form action="sell.php" method="post">
    <fieldset>
        <div class="control-group">
            <select name="symbol">
                <option value=''>Select stock</option>
                    <?php
                        
                        foreach($stocks as $symbol)
                        {
                            echo("<option value='$symbol'>" . $symbol . "</option>");
                        }
                    
                    ?>
                
            </select>
        </div>
        <div class="control-group">
            <button class="btn btn-default" type="submit">
                <span aria-hidden="true" class="glyphicon glyphicon-log-in"></span>
                Sell Shares
            </button>
        </div>
    </fieldset>
</form>

