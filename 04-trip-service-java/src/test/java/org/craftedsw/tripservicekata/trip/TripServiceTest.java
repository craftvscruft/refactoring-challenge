package org.craftedsw.tripservicekata.trip;

import org.craftedsw.tripservicekata.exception.UserNotLoggedInException;
import org.craftedsw.tripservicekata.user.User;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

public class TripServiceTest {
    private TripService subject;
    private FakeTripDAO tripDAO;
    private FakeUserSession session;

    @BeforeEach
    public void setup() {
        subject = new TripService();
        tripDAO = new FakeTripDAO();
        session = new FakeUserSession();
    }

	@Test
    public void findUserTripsWhenLoggedInUserIsFriend() {
        session.loggedUser = new User();
        User user = new User();
        user.addFriend(session.getLoggedUser());
        Trip trip = new Trip();
        tripDAO.foundTrips.add(trip);

        List<Trip> result = subject.getTripsByUser(user, session, tripDAO);

        assertEquals(1, result.size());
        assertSame(trip, result.get(0));
        assertSame(user, tripDAO.passedUser);
    }

    @Test
    public void findNoUserTripsWhenLoggedInUserIsNotFriend() {
        session.loggedUser = new User();
        User user = new User();
        Trip trip = new Trip();
        tripDAO.foundTrips.add(trip);

        List<Trip> result = subject.getTripsByUser(user, session, tripDAO);

        assertEquals(0, result.size());
    }

    @Test
    public void throwsWhenNoLoggedInUser() {
        User user = new User();
        Trip trip = new Trip();
        tripDAO.foundTrips.add(trip);
        
        assertThrows(UserNotLoggedInException.class, () -> {
            subject.getTripsByUser(user, session, tripDAO);
        });
    }
}
