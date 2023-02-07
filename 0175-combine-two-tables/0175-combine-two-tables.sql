SELECT firstName, lastName, city, state
From Person
LEFT JOIN Address
    ON Person.personID = Address.personID;