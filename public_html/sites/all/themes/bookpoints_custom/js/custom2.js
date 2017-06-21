(function ($){
    $(document).ready(function () {
        $( "#view-badges-mobile" ).click(function() {
            $( "#badges-box" ).toggle( "fast", function() {
             });
        });
        $(".page-library-dashboard-readers-reader-overview .add_activity_panel input").val("Add Reading Log");
        $(".page-library-dashboard-readers-reader-overview .reader_update_panel input").val("Edit Reader");
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
