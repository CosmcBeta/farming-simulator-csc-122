# Portfolio 2 Acceptance Criteria
You are going to build upon the farming simulator game that you started in Portfolio 1. You must build your submission upon your work from Portfolio 1. You are allowed to edit, update, or delete portions of your code from Portfolio 1 in order to make it work for Portfolio 2. You are not allowed to “throw away” your entire submission from Portfolio 1 and start from scratch for Portfolio 2. If you are unsure whether deleting something is too extreme, please ask! I am happy to chat with you about options for refactoring.
## Realistic Vegetables
I want to grow more than just carrots on my farm! I want to be able to plant a variety of
vegetables and watch them grow over time.
- [ ] As a player, I should be able to plant the seeds outlined in the table below.
  - [x] You should update the legend of your game to indicate how to plant each of the vegetables.
  - [ ] You are not allowed to plant a seed on top of another existing seed or plant.
- [ ] Each vegetable is planted as a seed and grows over time.
  - [ ] When a seed is planted in a plot, the plot is represented as “tilled soil”.
  - [ ] After some number of days, the seed in the tilled soil sprouts into a seedling.
  - [ ] Then, after another number of days, the seed matures into an adult plant.
- [ ] You can only harvest from an adult plant.
  - [ ] Nothing happens if you try to harvest from tilled soil or a seedling.
  - [ ] When you harvest an adult plant, the plot returns to bare soil, just like in Portfolio 1.
- [ ] You are free to determine what the seeds, seedlings, and mature plants look like according to the following rules.
  - [ ] When you plant a seed, you should see a "tilled soil" symbol on the plot which represents digging up the soil to plant a seed. As the seed grows, it will convert to a “seedling” symbol and then an “adult plant” symbol.
  - [ ] A tilled soil plot, a seedling, and an adult plant should all have distinct symbols.
  - [ ] Tilled soil plots and seedlings can share the same symbol between different plants, if you wish.
  - [ ] The symbols for adult plants must all be distinct between plants.

| Plant | Days to Sprout | Days to Maturity |
| ----- | -------------- | ---------------- |
| Carrot | 1 | 1 |
| Lettuce | 2 | 2 |
| Spinach | 2 | 3 |
| Beet | 2 | 5 |
| Brussels Sprouts | 5 | 10 |

## Watering Plants
A well-watered plant is a happy plant! I want to be able to water the plants in my garden to
speed up their growth.
- [ ] I should be able to water a plant by standing on a plot and using a keyboard command.
- [x] You should update the game legend to explain how to water a plant.
- [ ] If I water an empty plot of land (i.e. bare soil), nothing happens.
- [ ] If I water a plot of land with a vegetable planted on it, it will mature by two days when the day ends rather than just one.
  - [ ] A watered plant should NOT immediately mature in the middle of the day. It should mature by two days at the end of the day.
- [ ] If I repeatedly water a vegetable, nothing happens on each successive watering on that day.
  - [ ] In other words, a plant can mature by “two days”, at most.
