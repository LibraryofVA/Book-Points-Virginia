$(document).ready(function () {
     $('.activity-button').click(function(){
        var clickBtnValue = $(this).data();
        var reader_id = $(this).data("reader");
        var activity_id = $(this).data("activity");
        var ajaxurl = '/activity/log/claim/' + reader_id + "/" + activity_id,
        jQuery(".activity-button").load(ajaxurl);
    });
});