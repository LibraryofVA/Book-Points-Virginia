(function ($){
	$(document).ready(function () {
	   $('.program-buttons').on('click', function(){

	   var $id = $(this).attr('id');

	   var $id_short = "#" + $id.substring(8, $id.length);

	   	$($id_short).prop("checked", true);

	   	 $('#galecia-profile-builder-form').submit();
	   		
	   });

	   $( "#view-badges-mobile" ).click(function() {
             $( "#badges-box" ).toggle( "fast", function() {
             });
       });
	})
}(jQuery));
