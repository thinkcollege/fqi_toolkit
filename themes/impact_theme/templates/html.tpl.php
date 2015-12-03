<!DOCTYPE html>
<html lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>"<?php print $rdf_namespaces; ?>>
<head>
<?php print $head; ?>
<link href='http://fonts.googleapis.com/css?family=Architects+Daughter' rel='stylesheet' type='text/css'>
<title><?php print $head_title; ?></title>
<?php print $styles; ?>
<?php print $scripts; ?>
<script>
jQuery.noConflict();
jQuery( document ).ready(function() {
jQuery(".toggler").click(function(){
  jQuery(this).next().slideToggle("slow");
  return false;
}).next().hide(); })</script>
<!--[if lt IE 9]><script src="<?php print base_path() . drupal_get_path('theme', 'impact_theme') . '/js/html5.js'; ?>"></script><![endif]-->
</head>
<body class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <?php print $page_top; ?>
  <?php print $page; ?>
  <?php print $page_bottom; ?>
</body>
</html>