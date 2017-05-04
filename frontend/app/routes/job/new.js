import Ember from 'ember';
import RSVP from 'rsvp';

export default Ember.Route.extend({
  model(){
    this._super(...arguments);
    return RSVP.hash({
      job: {},
      datasources: this.store.findAll('datasource'),
    });
  },

  setupController(controller, model) {
    this._super(controller, model);
    this.controller.set('datasource', null);
  },
});