(function ($){
$(document).ready(function () {
     $('.activity-button').click(function(){
        var clickBtnValue = $(this).data();
        var reader_id = $(this).data("reader");
        var activity_id = $(this).data("activity");
        var ajaxurl = '/activity/log/claim/' + reader_id + "/" + activity_id;
        $(this).load(ajaxurl, function(responseTxt, statusTxt, xhr){
           	location.reload();
   		});


    });
});
}(jQuery));