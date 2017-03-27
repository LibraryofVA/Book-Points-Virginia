(function ($){
	$(document).ready(function () {
	    $('.stars').click(function () {
	    	$( this ).nextAll().removeClass( "star-add" );
	    	$( this ).prevAll().addClass( "star-add" );
	    });    
	})
}(jQuery));