Parsing
    Lire la map .cub
    Vérifier les erreurs (murs fermés, caractères valides, etc.)

Initialisation
    MiniLibX
    Fenêtre
    Gestion des inputs

Raycasting
    Calcul des rayons
    Détection des murs
    Distance + correction fish-eye

Rendering
    Dessiner les murs (vertical lines)
    Ajouter textures

Bonus
    minimap   <---- PEUT ETRE UTILE POUR DEBUG
    sprites
    portes
    souris


1 -> Du coup premiere etape parsing + afficher avec l'aide d'une fonction debug tyout ce qu'on a stocker et gerer les edge case du parsing directement



            PARSE
            ↓
            t_arg

            INIT
            ↓
            mlx_init
            ↓
            window
            ↓
            image
            ↓
            game state (player/map/colors)
            ↓
            textures
            ↓
            render loop
                