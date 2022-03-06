package org.craftedsw.tripservicekata.trip;

import java.util.ArrayList;
import java.util.List;

import org.craftedsw.tripservicekata.exception.UserNotLoggedInException;
import org.craftedsw.tripservicekata.user.IUserSession;
import org.craftedsw.tripservicekata.user.User;
import org.craftedsw.tripservicekata.user.UserSession;

public class TripService {
	private final ITripDAO tripDAO;

	public TripService(ITripDAO tripDAO) {
		this.tripDAO = tripDAO;
	}

	public List<Trip> getTripsByUser(User user) throws UserNotLoggedInException {
		return getTripsByUser(user, UserSession.getInstance());
	}

	List<Trip> getTripsByUser(User user, IUserSession session) {
		User loggedUser = session.getLoggedUser();
		if (loggedUser == null) {
			throw new UserNotLoggedInException();
		}
		if (isFriend(user, loggedUser)) {
			return tripDAO.findTripsByUser(user);
		}
		return new ArrayList<>();
	}

	private boolean isFriend(User user, User maybeFriend) {
		return user.getFriends().stream().anyMatch((f) -> f.equals(maybeFriend));
	}

}
