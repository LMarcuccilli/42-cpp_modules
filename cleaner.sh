#!/bin/bash

# Script pour faire un make fclean dans tous les dossiers ex* à l'intérieur de chaque cpp*

# Parcourir tous les dossiers cpp*
for cpp_dir in cpp*/ ; do
    if [ -d "$cpp_dir" ]; then
        echo "Entering $cpp_dir"

        # Parcourir tous les dossiers ex* à l'intérieur du dossier cpp*
        for ex_dir in "$cpp_dir"ex*/ ; do
            if [ -d "$ex_dir" ]; then
                echo "  Cleaning $ex_dir"
                (cd "$ex_dir" && make fclean)
            fi
        done
    fi
done

echo "Done!"

