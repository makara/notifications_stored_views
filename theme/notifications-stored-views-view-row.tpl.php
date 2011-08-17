<?php if (isset($fields['title'])): ?>
<h2><?php print $fields['title']; ?></h2>
<?php endif; ?>
<?php if (isset($fields['timestamp'])): ?>
<p><?php print $fields['timestamp']; ?></p>
<?php endif; ?>
<hr>
<?php if (isset($fields['description'])): ?>
<p><?php print $fields['description']; ?></p>
<?php endif; ?>
