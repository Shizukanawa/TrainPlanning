# TrainPlanning

A University project for 1st semester about making software that prints a table with the trainschedule and finding a route from a users input.

## Running the software
Download from the release at: https://github.com/Shizukanawa/TrainPlanning/releases/latest
1. Run main.exe while having `Stationer.txt` in the same folder
2. When asked for a start destination enter a station name starting with a capital letter and the rest with lowercase letters
    1. With special letters like `æ` `ø` `å` please write `ae` `oe` `aa` respectively
3. Enter an end destination with the same limitations
4. Your route will now be displayed

## Available stations
| Station Name  | Corresponding number | Connections* |
| ------------- | -------------------- | ------------ |
| Aalborg       | 0                    | 1, 99, 99    |
| Skalborg      | 1                    | 0, 2, 99     |
| Svenstrup     | 2                    | 1, 3, 99     |
| Stoevring     | 3                    | 2, 4, 99     |
| Skoerping     | 4                    | 3, 5, 99     |
| Arden         | 5                    | 4, 6, 99     |
| Hobro         | 6                    | 5, 7, 99     |
| Randers       | 7                    | 6, 8, 99     |
| Langå         | 8                    | 7, 9, 99     |
| Hadsten       | 9                    | 8 ,10 ,99    |
| Århus         | 10                   | 9, 11, 99    |
| Skanderborg   | 11                   | 10, 12, 99   |
| Horsens       | 12                   | 11, 13, 99   |
| Vejle         | 13                   | 12, 14, 99   |
| Fredericia    | 14                   | 13, 15, 99   |
| Middelfart    | 15                   | 14, 16, 99   |
| Odense        | 16                   | 15, 17, 99   |
| Langeskov     | 17                   | 16, 18, 99   |
| Nyborg        | 18                   | 17, 19, 99   |
| Korsoer       | 19                   | 18, 20, 99   |
| Slagelse      | 20                   | 19, 21, 99   |
| Sorø          | 21                   | 20, 22, 99   |
| Ringsted      | 22                   | 21, 23, 99   |
| Roskilde      | 23                   | 22, 24, 99   |
| Høje Taastrup | 24                   | 23, 25, 99   |
| Valby         | 25                   | 24, 26, 99   |
| København     | 26                   | 25, 99, 99   |

*99 is "NULL" in this case
