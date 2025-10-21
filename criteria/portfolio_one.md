# Portfolio 1 Acceptance Criteria
You are going to build a miniature farming simulator game that can be played in the
console.
## Gameplay
- [ ] You need to implement some way to gracefully end the game.
- [ ] Users should be able to move, plant a vegetable, harvest vegetables, and end the day.
- [ ] You must implement a legend that explains the controls of the game. It should include details on how to move, plant a vegetable, harvest vegetables, end the day, and exit the game.
- [ ] The farm should be rectangular. You can decide on its dimensions.
## Moving
- [ ] Players can move up, down, left, or right on the grid.
- [ ] When the player tries to move past the boundaries of the farm, there should be some mechanism that keeps them from going off the grid.
## Ending the Day
- [ ] You must display the current day in the console.
	- [ ] We start the game on day one.
	- [ ] Every time you end the day, the day number increments by one.
## Planting
- [ ] You must implement one vegetable with a seedling and mature state, at a minimum. This vegetable has the following properties:
	- [ ] It must have a name (decided by the developer).
	- [ ] It takes up one square plot on the farm.
	- [ ] When you plant the vegetable, it is displayed as a seedling on the farm grid.
  - [ ] After one day, it becomes mature and is displayed using a different symbol on the farm grid. It does not grow or die past the mature state unless you harvest it.
- [ ] You cannot plant a new plant on a spot that already has a plant on it.
## Harvesting
- [ ] You can only harvest mature plants.
- [ ] You cannot harvest from a spot that is an “Empty” plot.
- [ ] When you harvest a vegetable, the soil plot should return to its “Empty” state.
## General
- [ ] You must implement a farming simulator that can be played on the console.
- [ ] The game must work cross-platform (e.g. you cannot use conio or window to implement movement).
- [ ] I expect to see consistent theming in the app (e.g. all the plants of one type should look the same, soil plots should be neatly spaced, etc.).
- [ ] Your game must handle random inputs from users. It should never crash.
- [ ] Your game must be well-tested using the unit tests / driver program structure we have practiced in class.
