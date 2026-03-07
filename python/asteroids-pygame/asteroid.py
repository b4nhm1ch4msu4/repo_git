import pygame
import random
from constants import LINE_WIDTH, ASTEROID_MIN_RADIUS
from circleshape import CircleShape
from logger import log_event


class Asteroid(CircleShape):
    def __init__(self, x, y, radius):
        super().__init__(x, y, radius)

    def draw(self, screen):
        pygame.draw.circle(
            screen, (255, 255, 255), self.position, self.radius, LINE_WIDTH
        )

    def update(self, dt):
        self.position += self.velocity * dt

    def split(self):
        self.kill()
        if self.radius <= ASTEROID_MIN_RADIUS:
            return
        else:
            log_event("asteroid_split")
            new_angle = random.uniform(20,50)
            first_rotation = self.velocity.rotate(new_angle)
            second_rotation = self.velocity.rotate(-new_angle)
            first_child_asteroid = Asteroid(self.position.x, self.position.y,self.radius - ASTEROID_MIN_RADIUS)
            first_child_asteroid.velocity = first_rotation * 1.2
            second_child_asteroid = Asteroid(self.position.x, self.position.y,self.radius - ASTEROID_MIN_RADIUS)
            second_child_asteroid.velocity = second_rotation * 1.2
