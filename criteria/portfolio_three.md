# Portfolio 3
Bunnies are a pest in the garden. They look cute and innocent, but they will eat your plants and poop all over everything you have worked so hard to build. We are going to simulate the horrors of bunny rabbits on the farm. The goal of this feature is to simulate bunny rabbits wandering in and out of your farm. They move around the farm at the end of each day. If a bunny starts the day on a plant, it eats the plant. If you get close to the bunny, it will run away from you.

## Bunnies

- [ ] A bunny rabbit should have a unique symbol.
- [ ] At the start of the day, there is a chance that a bunny rabbit will appear on the edge of the farm.
  - [ ] You can choose what the percent chance is that a bunny will appear in the farm, as long as it is greater than zero.
  - [ ] You can choose where along the edge the bunny will appear (e.g. same spot every time? random spot?)
  - [ ] You can choose if you want one bunny in the farm at a time or many bunnies.
  - [ ] You can use the same symbol for multiple bunnies if you choose to go down that route.
- [ ] At the start of each day, the bunny rabbit moves to an adjacent plot.
  - [ ] The bunny should move one square (up, down, left, or right) at the end of each day.
  - [ ] You can choose the pattern of how the bunny moves (e.g. random, straight line, zig zag, whatever you want).
  - [ ] Unlike a player, the bunny can move off the map. If it does, it has run away and does not come back. You have to wait for a brand new bunny to spawn.
  - [ ] The bunny should never end up on the same spot as the player.
- [ ] At the start of the day, if a bunny is on top of a vegetable, the vegetable is eaten and the plot becomes "regular soil".
- [ ] If the player moves into one of the 4 squares around a bunny (i.e. up, down, left, right), the bunny becomes scared and runs away.
  - [ ] The next movement the bunny takes at the end of the day is four squares, directly away from the player.
  - [ ] Once the bunny is away from the player, it goes back to its normal movement.
  - [ ] You can decide if the bunny runs away immediately after the player ends up next to it or if the bunny waits until the end of the day to run away.
