package org.craftedsw.tripservicekata.trip;

import org.craftedsw.tripservicekata.user.User;
import org.junit.jupiter.api.Test;

import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

public class TripServiceTest {
	@Test
    public void findUserTripsWhenLoggedInUserIsFriend() {
        TripService subject = new TripService();
        FakeTripDAO tripDAO = new FakeTripDAO();
        FakeUserSession session = new FakeUserSession();
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
}
