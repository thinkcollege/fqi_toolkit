/*-------------------------------------------------------------------- 
 * JQuery Plugin: "EqualHeights" & "EqualWidths"
 * by:	Scott Jehl, Todd Parker, Maggie Costello Wachs (http://www.filamentgroup.com)
 *
 * Copyright (c) 2007 Filament Group
 * Licensed under GPL (http://www.opensource.org/licenses/gpl-license.php)
 *
 * Description: Compares the heights or widths of the top-level children of a provided element 
 		and sets their min-height to the tallest height (or width to widest width). Sets in em units 
 		by default if pxToEm() method is available.
 * Dependencies: jQuery library, pxToEm method	(article: http://www.filamentgroup.com/lab/retaining_scalable_interfaces_with_pixel_to_em_conversion/)							  
 * Usage Example: $(element).equalHeights();
   						      Optional: to set min-height in px, pass a true argument: $(element).equalHeights(true);
 * Version: 2.0, 07.24.2008
 * Changelog:
 *  08.02.2007 initial Version 1.0
 *  07.24.2008 v 2.0 - added support for widths
--------------------------------------------------------------------*/
 (function($) {

     $.fn.equalHeights = function(options) {
         var maxHeight = 0,
             $this = $(this),
             equalHeightsFn = function() {
                 var height = $(this).innerHeight();
    
                 if ( height > maxHeight ) { maxHeight = height; }
             };
         options = options || {};

         $this.each(equalHeightsFn);

         if(options.wait) {
             var loop = setInterval(function() {
                 if(maxHeight > 0) {
                     clearInterval(loop);
                     return $this.css('height', maxHeight);
                 }
                 $this.each(equalHeightsFn);
             }, 100);
         } else {
             return $this.css('height', maxHeight);
         }
     };

     // auto-initialize plugin
     $('[data-equal]').each(function(){
         var $this = $(this),
             target = $this.data('equal');
         $this.find(target).equalHeights();
     });

 })(jQuery);