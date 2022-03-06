package org.craftedsw.tripservicekata.trip;

import org.craftedsw.tripservicekata.user.User;

import java.util.ArrayList;
import java.util.List;

public class FakeTripDAO implements ITripDAO {
    public List<Trip> foundTrips = new ArrayList<>();
    public User passedUser = null;
    @Override
    public List<Trip> findTripsByUser(User user) {
        passedUser = user;
        return foundTrips;
    }
}
