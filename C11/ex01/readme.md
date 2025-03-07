Don't forget to add these 2 lines at the beginning of the ft_map, because length is a parameter could be < 1, so to avoid this kind of case, we need to secure the function at the beginning.
 if (length < 1)
                return (NULL);

