# Notes file from video

## Used whenever you need to have a subscriber/publisher pattern

Such as signals in [Godot](https://godotengine.org)

## Information about design pattern

* Publisher doesn't need to know anything about subscribers
* The subject(publisher) maintains a list of its dependants, or observers(followers)
* The subject then notifies all of the followers of any changes

## Information about implementation

* Usually an interface for an observer, or follower is implemented for subscribers
* Ususally observer has an `update` method, called whenver there's an update
* Usually publisher has three methods:
* * `register` - For adding a new subscriber
* * `unregister` - For deleting a current subscriber
* * `notifyObserver` - For notifying all observers, or followers