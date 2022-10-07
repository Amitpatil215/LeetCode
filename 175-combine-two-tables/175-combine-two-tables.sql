# Write your MySQL query statement below

Select firstName, lastName, city, state
from person
Left JOIN Address on person.personId = Address.personId;