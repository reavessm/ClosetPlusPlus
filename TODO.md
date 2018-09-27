# Things to work on

- Implement SQLite API for opening and closing closets
    * Increase `num_of_clothes` on backend.Init() by 
    
    ```sql
    SELECT count(*) from Shirts;
    ```

    * Option for SQLite, Redis, or MongoDB
- Create function to pick random article of clothing and suggested clothing
- Create function for suggested clothing
- Disallow duplicate names in closet
- Create function to import and export from JSON
