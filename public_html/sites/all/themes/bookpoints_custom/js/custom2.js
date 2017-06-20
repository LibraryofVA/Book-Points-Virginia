(function ($){
	$(document).ready(function () {
           $( "#view-badges-mobile" ).click(function() {
             $( "#badges-box" ).toggle( "fast", function() {
             });
           });

	})
var resizeTimer;
$(window).on('resize', function (e) {
    clearTimeout(resizeTimer);
    resizeTimer = setTimeout(function () {
        if ($(window).width() > 768) {
            $('#badges-box').show();
        } else {
            $('#badges-box').hide();
        }
    }, 250);
});
}(jQuery));
