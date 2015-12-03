/* 
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
jQuery(document).ready(function(){

    jQuery('div#block-menu-menu-lesson-plan-menu li a').hide();// hide all nav
    jQuery('div#lessonplan-content > div').hide();// hide all content    
    jQuery('div#lessonplan-content div#lessonbasics').show();
    jQuery('div#lessonplan-content div#lessonbasics').toggleClass('active');; // show the first div of content
    jQuery('div#block-menu-menu-lesson-plan-menu li a[href=#lessonbasics]').toggleClass('active'); // show the first div of content
    
    jQuery('div#block-menu-menu-lesson-plan-menu li a').each(function(){
        var currentTittle = jQuery(this).attr('title');
        jQuery(this).attr('href','#' + currentTittle);
        jQuery(this).attr('title','');
    });
    
    jQuery('div#block-menu-menu-lesson-plan-menu li a[href=#lessonbasics]').toggleClass('active'); // show the first div of content
       
    jQuery('div#lessonplan-content > div').each(function(){
        var currentId = jQuery(this).attr('id');
        //alert(currentId);
        jQuery('div#block-menu-menu-lesson-plan-menu li a[href=#'+currentId+']').show();
    });
    
    
   jQuery('span.leftLabel').each(function(){
       if ( (jQuery(this).text().trim().length) && (jQuery(this).text() != "&nbsp;") ){
            jQuery(this).replaceWith( "<h6>" + jQuery( this ).text() + "</h6>" );
	}
   });
           
   
  function convertToList() {
  var list =  jQuery("<ul></ul>");
  jQuery("div#lessonplan-content div table tbody tr td").each(function() {
    //var children = jQuery(this).children();
    list.append("<li>" +jQuery(this).html()+ "</li>");
    });
  
   jQuery("table").replaceWith(list);
  }
      
  //  convertToList();
    
    jQuery('div#block-menu-menu-lesson-plan-menu li a').click(function(){
        
        jQuery('div#block-menu-menu-lesson-plan-menu li a').removeClass('active');
        jQuery(this).addClass('active');
        // 
        jQuery('div.active').toggle(10);
        jQuery('div.active').removeClass('active');
        //
        var target = jQuery(this).attr('href');
        jQuery(target).toggle(10);
        jQuery(target).addClass('active');
    });
});

