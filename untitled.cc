<?php
ini_set('display_errors', 0);
error_reporting(E_ALL);

$feedurl = "http://www.futurequestisland.org/toolkit/sites/teachers.futurequestisland.org/templesson.xml";
//$feedurl = "http://resources21.org/cl/fqiprojectfeed.asp";
function scrapePage($url) {
	$ch = curl_init();
curl_setopt($ch, CURLOPT_URL, $url);
curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
$data = curl_exec($ch);
curl_close($ch);
return $data; }

function innerXML($node) { $doc = $node->ownerDocument; $frag = $doc->createDocumentFragment(); foreach ($node->childNodes as $child) { $frag->appendChild($child->cloneNode(TRUE)); } return $doc->saveXML($frag); }
function outputScrape($url) { 
	$returnvalue = "" ;
	$data1 = preg_replace('#(<\/ul>\s*)+#i', '</ul>',scrapePage($url));
$data1a = str_replace('files//', 'http://resources21.org/cl/files/',$data1);

$data2 = preg_replace(array('/<head>(.*)<\/head>/iUs', '/<html>/','/<\/html>/','/<body>/', '/<\/body>/','/<\/td><td>/'), "",$data1a);

$returnvalue .= '<div id="lessonplan-content">';

	$doc = new DOMDocument();
	$doc->loadHTML($data2);
libxml_use_internal_errors(false);
	$xpath = new DOMXpath($doc);


$elements = $xpath->query('//ul');
$elementsh = $xpath->query("//*[@class='secHed']");
$header = array();
if (!is_null($elementsh)) {
	
  foreach ($elementsh as $elementh) {
$header[] = "<h3>". $elementh->nodeValue . "</h3>";

   
  }
} 


	
	if (!is_null($elements)) { $i = 0;
	  foreach ($elements as $element) {
	    $returnvalue .= '<div id="' .$element->getAttribute('id') . '">' . $header[$i]  ."<ul>";

	    $nodes = $element->childNodes;
	    foreach ($nodes as $node) {
	      $returnvalue .= '<li>' . innerXML($node). "</li>\n";
	    } $returnvalue .= "</ul></div>";  $i++;
	  } 
	  $returnvalue .= "</div>";
	 
	} 
	// $returnvalue = "<[CDATA[ " . $returnvalue ." ]]>";
	return $returnvalue;
}





$xmlstr = scrapePage($feedurl);

 $xmlstr = preg_replace('/<rss version="2.0">/','<rss version="2.0" xmlns:content="http://purl.org/rss/1.0/modules/content/">',$xmlstr);
// $xmlstr = preg_replace( '/<channel>/', '<channel xmlns="http://www.w3schools.com" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" // xsi:schemaLocation="file:///feed_scraper.xsd">' ,$xmlstr);
$output = new SimpleXMLElement($xmlstr);
$lessonurls = array();
foreach ($output->channel->item as $element) { 
	
	$title = $element->title;
	$lessonurls[] = (string) $element->description[0];
// echo preg_replace(array('/Future Quest Island - /','/Future Quest Island/'), '',"$title") . "<br />" . $element->description . "<br /><br />";
 } 

$xmlObj = getDoc();

$nsNode = $xmlObj->channel;
$i = 0;
 foreach($nsNode->item as $lowlev) { 
	 
	 if ($lowlev !== null) {  $contentfield =$lowlev->addChild('content:encoded', outputScrape($lessonurls[$i]), "http://purl.org/rss/1.0/modules/content/") ; $i = $i + 1; } } 
$xmloutput = $xmlObj->asxml();

function getDoc() {
	global $feedurl;
	global $xmlstr;
  return new SimpleXMLElement($xmlstr);
}


$xmlFile = "/usr/lib/php/drupal/7.x_sites/teachers.futurequestisland.org/files/lessonscraper.xml";

$fh = fopen($xmlFile, 'w') or die("can't open file");
$stringData = "$xmloutput";
fwrite($fh, $stringData);
fclose($fh);


	?>
