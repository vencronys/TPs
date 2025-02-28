document.addEventListener("DOMContentLoaded", function() {
    var date = new Date();
    var formattedDate = date.getDate().toString().padStart(2, '0') + '-' +
        (date.getMonth() + 1).toString().padStart(2, '0') + '-' +
        date.getFullYear();

    const xhr = new XMLHttpRequest();
    xhr.open("GET", `https://api.aladhan.com/v1/timings/${formattedDate}?latitude=34.6813900&longitude=-1.9085800&method=3&shafaq=general&tune=5%2C3%2C5%2C7%2C9%2C-1%2C0%2C8%2C-6&timezonestring=Africa%2FCasablanca&calendarMethod=UAQ`);

    xhr.onload = function() {
        if (xhr.status === 200) {
            var data = JSON.parse(xhr.responseText);
            var timings = data.data.timings;

            // Select all <td> elements
            var tds = document.querySelectorAll("td");

            // Update the table with prayer times
            tds[0].textContent = timings.Fajr;
            tds[1].textContent = timings.Dhuhr;
            tds[2].textContent = timings.Asr;
            tds[3].textContent = timings.Maghrib;
            tds[4].textContent = timings.Isha;
        } else {
            console.error("Failed to fetch data. Status:", xhr.status);
        }
    };

    xhr.onerror = function() {
        console.log("Request failed");
    };

    xhr.send();
});

