import Ember from 'ember';

export default Ember.Route.extend({
  session: Ember.inject.service('session'),

  beforeModel(){
    var isAuthenticated = this.get('session.isAuthenticated');
    if(isAuthenticated){
      this.replaceWith('ferramenta.filtros');
    } else {
      this.replaceWith('landing-page');
    }
  }
});
