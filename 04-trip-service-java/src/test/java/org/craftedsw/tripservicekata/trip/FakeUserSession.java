package org.craftedsw.tripservicekata.trip;

import org.craftedsw.tripservicekata.user.IUserSession;
import org.craftedsw.tripservicekata.user.User;

public class FakeUserSession implements IUserSession {
    public User loggedUser;
    @Override
    public User getLoggedUser() {
        return loggedUser;
    }
}
