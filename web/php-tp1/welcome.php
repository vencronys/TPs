<?php
if (
    !isset($_POST['nom'])
    || !isset($_POST['prenom'])
    || !isset($_POST['date_naissance'])
    || !isset($_POST['moyenne'])
    || !isset($_POST['niveau'])
    || !isset($_POST['langues'])
    || !isset($_POST['sexe'])
    || !isset($_POST['adresse'])
) {
    echo "Erreur : Vous n'avez pas rempli le formulaire correctement.";
    exit;
}

$nom = $_POST['nom'];
$prenom = $_POST['prenom'];
$date_naissance = $_POST['date_naissance'];
$moyenne = $_POST['moyenne'];
$niveau = $_POST['niveau'];
$langues = $_POST['langues'];
$sexe = $_POST['sexe'];
$adresse = $_POST['adresse'];

if (empty($nom)) {
    echo "Erreur : Le nom est vide.";
    exit;
}

if (!preg_match("/[a-zA-Z]{3,30}/", $nom)
    || !preg_match("/[a-zA-Z]{3,30}/", $prenom)) {
    echo "Erreur : Le nom et le prenom doit contenir entre 3 et 30 caractères.";
    exit;
}

if (!validateDate($date_naissance)) {
    echo "Erreur : La date de naissance n'est pas valide.";
}

$age = date_diff(date_create($date_naissance), date_create('now'))->y;

if (!is_numeric($moyenne)) {
    echo "Erreur : La moyenne doit être un nombre.";
    exit;
}

if (!preg_match("/bac[235]?/", $niveau)) {
    echo "Erreur : Le niveau doit être bac, bac1, bac2, bac3 ou bac 5.";
    exit;
}

foreach ($langues as $langue) {
    if (!in_array($langue, ['AR', 'FR', 'EN'])) {
        echo "Erreur : La langue doit être soit AR, FR ou EN.";
        exit;
    }
}

if (!($sexe == "homme" || $sexe == "femme")) {
    echo "Erreur : Le sexe doit être soit homme ou femme.";
    exit;
}

echo "Vous êtes $nom $prenom et vous avez $age ans. <br />";
echo "Votre moyenne est: $moyenne <br />";
echo "Votre niveau est: $niveau <br />";
echo "Vous parlez les langues suivantes:";
echo "<ul>";
foreach ($langues as $langue) {
    echo " <li> $langue </li>";
}
echo "</ul>";
echo "Votre sexe: $sexe <br />";
echo "Vous habitez à $adresse <br />";

function validateDate($date) { 
	list($year, $month, $day) = explode('-', $date); 
	return checkdate($month, $day, $year); 
} 