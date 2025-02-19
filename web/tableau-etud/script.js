let etudiants = [];

if (localStorage.getItem("etudiants")) {
  etudiants = JSON.parse(localStorage.getItem("etudiants"));
  DisplayEtudiant();
}

function addEtudiant() {
  let nom = document.getElementById("nom").value;
  let note = document.getElementById("note").value;
  if (nom === "" || note === "") {
    alert("Veuillez remplir tous les champs");
    return;
  }
  let etudiant = { nom: nom, note: note };
  etudiants.push(etudiant);
  console.log(etudiants);
  localStorage.clear();
  localStorage.setItem("etudiants", JSON.stringify(etudiants));
}

function DisplayEtudiant() {
  let table = document.getElementById("table");
  table.innerHTML = "";
  let headerRow = document.createElement("tr");
  let nameHeader = document.createElement("th");
  nameHeader.innerHTML = "Nom";
  let noteHeader = document.createElement("th");
  noteHeader.innerHTML = "Note";
  headerRow.appendChild(nameHeader);
  headerRow.appendChild(noteHeader);
  table.appendChild(headerRow);
  etudiants.forEach((etudiant) => {
    let tr = document.createElement("tr");
    let nameCell = document.createElement("td");
    let noteCell = document.createElement("td");
    nameCell.innerHTML = etudiant.nom;
    noteCell.innerHTML = etudiant.note;
    tr.appendChild(nameCell);
    tr.appendChild(noteCell);
    table.appendChild(tr);
  });
  document.querySelector("body").appendChild(table);
}

function getEtudiantsSupereurA10() {
  let etudiantsSupereurA10 = etudiants.filter(
    (etudiant) => parseInt(etudiant.note) > 10
  );
  DisplayEtudiantsParam(etudiantsSupereurA10);
}

function DisplayEtudiantsParam(array) {
  let table = document.getElementById("table");
  table.innerHTML = "";
  let headerRow = document.createElement("tr");
  let nameHeader = document.createElement("th");
  nameHeader.innerHTML = "Nom";
  let noteHeader = document.createElement("th");
  noteHeader.innerHTML = "Note";
  headerRow.appendChild(nameHeader);
  headerRow.appendChild(noteHeader);
  table.appendChild(headerRow);
  array.forEach((etudiant) => {
    let tr = document.createElement("tr");
    let nameCell = document.createElement("td");
    let noteCell = document.createElement("td");
    nameCell.innerHTML = etudiant.nom;
    noteCell.innerHTML = etudiant.note;
    tr.appendChild(nameCell);
    tr.appendChild(noteCell);
    table.appendChild(tr);
  });
  document.querySelector("body").appendChild(table);
}

function getMoyenne() {
  let somme = 0;
  etudiants.forEach((etudiant) => {
    somme += parseInt(etudiant.note);
  });
  document.getElementById("moyenne").innerHTML = `Moyenne: ${
    somme / etudiants.length
  }`;
}

function getMax() {
  let max = etudiants[0].note;
  etudiants.forEach((etudiant) => {
    if (parseInt(etudiant.note) > parseInt(max)) {
      max = etudiant.note;
    }
  });
  document.getElementById("max").innerHTML = `Max: ${max}`;
}

function getMin() {
  let min = etudiants[0].note;
  etudiants.forEach((etudiant) => {
    if (parseInt(etudiant.note) < parseInt(min)) {
      min = etudiant.note;
    }
  });
  document.getElementById("min").innerHTML = `Min: ${min}`;
}

function search() {
  let etudiantsSearched = [];
  let search = document.getElementById("search").value;
  if (search === "") {
    alert("Veuillez remplir le champ de recherche");
    return;
  }
  if (etudiants.length === 0) {
    alert("Pas d'étudiants");
    return;
  }
  if (isNaN(search)) {
    etudiantsSearched = etudiants.filter((etudiant) => etudiant.nom == search);
  } else {
    etudiantsSearched = etudiants.filter(
      (etudiant) => parseInt(etudiant.note) == parseInt(search)
    );
  }
  DisplayEtudiantsParam(etudiantsSearched);
}
