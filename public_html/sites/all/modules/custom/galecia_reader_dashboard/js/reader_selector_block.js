(function ($) {
   $( document ).ready(function() {

      console.log("hello");

      // define vars
      var nameOfForm = "reader-switch-form";
      var classOfReaderElement = "reader-element";
      var idOfFormElement = "edit-reader";

      // on click handler for each reader element
      $('.' + classOfReaderElement).on('click', function() {
         var id = $(this).data("reader-id");
         console.log("Logged");
        if(id != ""){
         $('#' + idOfFormElement).val(id);
         $('#' + nameOfForm).submit();
        }
      });
   });
}(jQuery));