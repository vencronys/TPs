// ----- CONFIGURATION -----
const API_KEY = "89fe666fa8b296e1865c76e3cf076cd1";
const DEFAULT_LAT = 37.6608241;
const DEFAULT_LON = -1.9462374;

// ----- GLOBAL DATA OBJECTS -----
let weatherData = null;

// ----- UTILITY FUNCTIONS -----
function formatTime(timestamp) {
  const date = new Date(timestamp * 1000);
  const hours = String(date.getHours()).padStart(2, "0");
  const minutes = String(date.getMinutes()).padStart(2, "0");
  return `${hours}:${minutes}`;
}

function getDayName(timestamp) {
  const date = new Date(timestamp * 1000);
  return date.toLocaleDateString("en-US", { weekday: "long" });
}

function getWeatherIcon(iconCode) {
  let faIconClass = "";
  switch (iconCode) {
    case "01d":
      faIconClass = "fa-sun";
      break;
    case "01n":
      faIconClass = "fa-moon";
      break;
    case "02d":
      faIconClass = "fa-cloud-sun";
      break;
    case "02n":
      faIconClass = "fa-cloud-moon";
      break;
    case "03d":
    case "03n":
      faIconClass = "fa-cloud";
      break;
    case "04d":
    case "04n":
      faIconClass = "fa-cloud-meatball";
      break;
    case "09d":
    case "09n":
      faIconClass = "fa-cloud-showers-heavy";
      break;
    case "10d":
    case "10n":
      faIconClass = "fa-cloud-rain";
      break;
    case "11d":
    case "11n":
      faIconClass = "fa-bolt";
      break;
    case "13d":
    case "13n":
      faIconClass = "fa-snowflake";
      break;
    case "50d":
    case "50n":
      faIconClass = "fa-smog";
      break;
    default:
      faIconClass = "fa-cloud";
  }
  return `<i class="fa-solid ${faIconClass}"></i>`;
}

// ----- GENERATE HTML ELEMENTS -----
function generateHourlyListItem(hourlyData) {
  const hourlyList = document.createElement("ul");
  hourlyList.innerHTML = `
    <li>${hourlyData.time}</li>
    <li>${getWeatherIcon(hourlyData.weather[0].icon)}</li>
    <li>${hourlyData.temp}°</li>
    <li><i class="fa-solid fa-droplet"></i> ${hourlyData.humidity}%</li>
  `;
  return hourlyList;
}

function generateDailyListItem(dailyData, index) {
  const dailyList = document.createElement("ul");
  dailyList.innerHTML = `
    <li>${index === 0 ? "Today" : dailyData.day}</li>
    <li><i class="fa-solid fa-droplet"></i> ${dailyData.humidity}%</li>
    <li>${getWeatherIcon(dailyData.weather[0].icon)}</li>
    <li>${Math.round(dailyData.temp.max)}°</li>
    <li>${Math.round(dailyData.temp.min)}°</li>
  `;
  return dailyList;
}

// ----- RENDER WEATHER DATA -----
function renderWeatherData() {
  if (!weatherData) return;

  const currentWeatherEl = document.querySelector(".header");
  currentWeatherEl.innerHTML = `
    <h1><span>${weatherData.current.temp}</span>°</h1>
    <h2>Oujda</h2>
    ${getWeatherIcon(weatherData.current.weather[0].icon)}
    <p>${weatherData.current.temp}° Feels like ${
    weatherData.current.feels_like
  }°</p>
    <p>${weatherData.current.day}, ${weatherData.current.time}</p>
  `;

  const hourlyContainer = document.querySelector(".hourly-container");
  hourlyContainer.innerHTML = "";
  weatherData.hourly.forEach((hourlyData) => {
    hourlyContainer.appendChild(generateHourlyListItem(hourlyData));
  });

  const dailyContainer = document.querySelector(".daily-container");
  dailyContainer.innerHTML = "";
  weatherData.daily.forEach((dailyData, index) => {
    dailyContainer.appendChild(generateDailyListItem(dailyData, index));
  });

  document.querySelector("#sunrise").textContent = weatherData.current.sunrise;
  document.querySelector("#sunset").textContent = weatherData.current.sunset;
}

// ----- FETCH WEATHER DATA -----
async function fetchWeatherData(lat, lon) {
  const API_URL = `https://api.openweathermap.org/data/3.0/onecall?lat=${lat}&lon=${lon}&units=metric&exclude=alerts,minutely&appid=${API_KEY}`;
  try {
    const response = await fetch(API_URL);
    const data = await response.json();

    weatherData = {
      current: {
        time: formatTime(data.current.dt),
        temp: Math.round(data.current.temp),
        feels_like: Math.round(data.current.feels_like),
        sunrise: formatTime(data.current.sunrise),
        sunset: formatTime(data.current.sunset),
        weather: data.current.weather,
        day: getDayName(data.current.dt),
      },
      hourly: data.hourly.slice(0, 12).map((hour) => ({
        time: formatTime(hour.dt),
        temp: Math.round(hour.temp),
        humidity: hour.humidity,
        weather: hour.weather,
        day: getDayName(hour.dt),
      })),
      daily: data.daily.map((day) => ({
        day: getDayName(day.dt),
        temp: day.temp,
        humidity: day.humidity,
        weather: day.weather,
      })),
    };

    console.log("Data:", data);
    console.log("Weather Data:", weatherData);
    renderWeatherData();
  } catch (error) {
    console.error("Error loading weather data:", error);
  }
}

// ----- INITIALIZE -----
document.addEventListener("DOMContentLoaded", () => {
  if ("geolocation" in navigator) {
    navigator.geolocation.getCurrentPosition(
      (position) => {
        const lat = position.coords.latitude;
        const lon = position.coords.longitude;
        console.log("Current Location:", { lat, lon });
        fetchWeatherData(lat, lon);
      },
      (error) => {
        console.error(`Geolocation error (${error.code}): ${error.message}`);
        // Fall back to default coordinates if error occurs
        fetchWeatherData(DEFAULT_LAT, DEFAULT_LON);
      },
      { enableHighAccuracy: true, timeout: 10000, maximumAge: 0 }
    );
  } else {
    console.error("Geolocation is not supported by this browser.");
    fetchWeatherData(DEFAULT_LAT, DEFAULT_LON);
  }
});

let deferredPrompt;

window.addEventListener("beforeinstallprompt", (event) => {
  event.preventDefault();
  deferredPrompt = event;
  document.getElementById("install-btn").style.display = "block";

  document.getElementById("install-btn").addEventListener("click", () => {
    deferredPrompt.prompt();
    deferredPrompt.userChoice.then((choiceResult) => {
      if (choiceResult.outcome === "accepted") {
        console.log("User accepted PWA install");
      } else {
        console.log("User dismissed PWA install");
      }
      deferredPrompt = null;
    });
  });
});
