
const xhr = new XMLHttpRequest();
xhr.open("GET","http://api.aladhan.com/v1/calendar?latitude=51.508515&longitude=-0.125487");

xhr.onload = function () {
    var tds = document.querySelectorAll("td");
    var date = new Date();
    console.log(tds);
    var data = JSON.parse(xhr.responseText);
    var data = data.data[23].timings;
    console.log(data);
    console.log(data);
    tds.forEach(function (td, index) {
    });
};

xhr.onerror = function () {

};

xhr.send();

