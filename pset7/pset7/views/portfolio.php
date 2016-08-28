<div>
    <div id="message">
    
        <?php
            print("Username: " . $cash[0]["username"] . "<br>Balance: $" . number_format($cash[0]["cash"], 2, '.', '.'));
        ?>
        
    </div>
    
    <table class="table table-striped">
    
        <thead>
            <tr>
                <th>Symbol</th>
                <th>Name</th>
                <th>Shares</th>
                <th>Price</th>
                <th>Total value</th>
            </tr>
        </thead>
    
        <tbody>
            
            <?php foreach($positions as $position): ?>
            
            <tr>
                <td><?= $position["symbol"] ?></td>
                <td><?= $position["name"] ?></td>
                <td><?= $position["shares"] ?></td>
                <td><?= "$" . $position["price"] ?></td>
                <td><?= "$" . number_format($position["value"], 2) ?></td>
                
            </tr>
            
            <?php endforeach ?>

        </tbody>
    
    </table>
    
</div>