
        DISTRIBUTEURS MODULE - README
______________________________________________________________________________

NAME:       Distributeurs
AUTHORS:    Pierre NOEL <contact@pierrenoel.pro>
______________________________________________________________________________


------------
Description
------------

Ce module customisé a pour but de d'introduire un système de comptes vendeurs/distributeurs et avec un jeu de commissions associé.
Fonctionne sous Drupal 7.

------------
Installation
------------

Installer et activer le module comme n'importe quel module ordinaire.

Ce module créé un role distributeur dont vous pouvez configurez les droits comme bon vous semble.

Il est nécessaire que chaque personne voulant être distributeur et bénéficier des avantages en rapport à ce
rôle, doit d'abord impérativement créer un compte utilisateur normal (ou s'en faire créer un par un administrateur).


/****  IMPORTANT  *********/
Le module permet de mettre en place facilement des remises(discounts) spéciales pour les distributeurs.
Bien que reposant sur le module Rules, je n'ai pas encore trouvé le moyen de permettre l'installation
automatique de règles de remises.
Il est néanmoins très facile de les importer en faisant un simple copier coller.
Dans le fichier distributeurs.rules_default.inc, vous trouverez les règles pré-établies, ainsi que celles
des remises dont il vous suffira de faire un copier coller à la bonne addresse.


Un guide pour les utilisateurs et un pour les administrateurs est disponible sur demande (contact email
mentionné plus haut).

Le sous-module espace professionnel fournit une page d'espace professionnel, regroupant plusieurs views dans un ensemble cohérent (plus d'infos dans le README du module).

------------
Usage
------------
-- Role distributeur
un nouveau rôle spécial pour les distributeurs

-- Distributeur relationship
Le module créé automatiquement une régle pour permettre la création d'une relation entre les utilisateurs
ordinaires et les distributeurs.
Les utilisateurs renseignant l'information correspondante à un professionnel lors de leur création de
compte créeront automatiquement (et de façon invisible) une relation entre leur compte et le compte du
distributeur.
Cette relation entre les deux comptes est la base sur laquelle viennent se greffer le système de
commissions distributeurs et de bon d'achat distributeurs.


-- Distributeur Commission
Lorsque qu'un utilisateur client passe une commande, et qu'une relation existe entre un distributeur et ce
client, alors un jeu de commission se déclenche. Il s'agit de règles (du module RULES) pré-conçues pouvant
être modifiées.

-- Distributeur bon d'achat
A chaque commission créée le distributeur voit le montant de la commission versé dans une "cagnote" interne
au site, appelé le champ distributeur bon d'achat.
Il peut ensuite utiliser le montant de cette cagnote comme un bon d'achat pour acheter des produits sur le
site.

-- Distributeur Remise
Les distributeurs ont également le droit à -20% de réduction automatique sur leurs achats sur le site
Cellfood (règle pré-conçue pouvant être modifiée).

