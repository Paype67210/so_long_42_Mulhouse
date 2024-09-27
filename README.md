<picture>
<img alt="Entête du dépôt ft_so_long." src="https://github.com/Paype67210/so_long_42_Mulhouse/blob/main/Tools/cover-so_long.png">
</picture>

### Objectifs du projet

- **Création d'une interface graphique** : Utilisation de la bibliothèque MiniLibX pour ouvrir une fenêtre, afficher des images, et gérer les événements du clavier.
- **Développement d'un jeu 2D** : Le joueur se déplace dans une carte (labyrinthe) avec des éléments à collecter, des obstacles à éviter, et une sortie à atteindre.
- **Gestion des événements clavier** : Réagir aux entrées utilisateur pour permettre au personnage de se déplacer sur la carte.
- **Optimisation de l'affichage** : Assurer une mise à jour fluide de l'écran lors des déplacements du joueur.

### Compétences acquises

- **Programmation graphique avec MiniLibX** : Bibliothèque légère développée pour l'école 42, la MiniLibX permet d'accéder à des fonctions basiques pour la manipulation graphique en C. Le projet **So_Long** enseigne plusieurs aspects techniques liés à son utilisation :
  - **Ouverture et gestion des fenêtres** : Apprentissage de la fonction `mlx_new_window()` pour créer une fenêtre où les éléments du jeu seront affichés, ainsi que la gestion des dimensions et de la fermeture propre de la fenêtre.
  - **Chargement et affichage d'images** : Utilisation de fonctions telles que `mlx_xpm_file_to_image()` et `mlx_put_image_to_window()` pour charger des fichiers d'images XPM, puis les afficher dans la fenêtre à des positions spécifiques.
  - **Manipulation de pixels et buffers** : Gestion de l'affichage pixel par pixel en modifiant directement la mémoire tampon via des fonctions comme `mlx_get_data_addr()`, permettant de comprendre le fonctionnement des buffers graphiques.
  - **Gestion des événements** : Implémentation de la capture d'événements clavier et souris avec `mlx_hook()` pour réagir aux actions de l'utilisateur en temps réel. Par exemple, le projet enseigne comment lier des touches du clavier aux mouvements du personnage dans le jeu avec `mlx_key_hook()`.

### Fonctionnalités du jeu

- **Carte du jeu** : Le jeu repose sur une carte (fichier `.ber`) qui représente le labyrinthe avec des murs, des objets à collecter et une sortie.
- **Déplacements du joueur** : Le joueur peut se déplacer dans les quatre directions (haut, bas, gauche, droite) en utilisant les touches du clavier.
- **Collecte d'objets** : Le joueur doit ramasser tous les objets présents sur la carte avant de pouvoir atteindre la sortie.
- **Victoire et conditions de fin** : Une fois tous les objets collectés, le joueur doit trouver la sortie pour gagner la partie.

### Possibilités d'amélioration (non implémentées)

Le projet **So_Long** peut être amélioré en ajoutant de nouvelles fonctionnalités :
- **Ajout de niveaux supplémentaires** avec des cartes plus complexes ou générées aléatoirement.
- **Gestion des collisions avancées** pour ajouter des ennemis ou des pièges dans le jeu.
- **Amélioration des graphismes** avec des animations pour les mouvements du joueur ou les interactions avec l'environnement.
- **Musique et effets sonores** pour rendre l'expérience de jeu plus immersive.

### Conclusion

Le projet **So_Long** offre une introduction solide aux concepts de base de la programmation graphique et à la gestion des événements en C. Il constitue un tremplin vers des projets plus complexes en développement de jeux et en programmation d'interface graphique. L'utilisation de la bibliothèque **MiniLibX** permet de comprendre les fondamentaux de la gestion des fenêtres, de l'affichage d'images et de la capture d'événements, tout en posant les bases pour des applications graphiques plus avancées.
**So_Long** (tout comme **File_de_Fer**) est une première étape avant de passer à **Cub3D** ou **miniRT**.

### Ressources supplémentaires

- [Documentation MiniLibX](https://harm-smits.github.io/42docs/libs/minilibx)
- [GitHub de la miniLibX Codam](https://github.com/codam-coding-college/MLX42/tree/master)
- [Tutoriel sur la programmation de jeux en 2D](https://www.raywenderlich.com/38732/introduction-to-2d-game-programming-in-c)
