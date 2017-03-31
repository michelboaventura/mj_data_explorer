import Ember from 'ember';

export default Ember.Component.extend({
  tagName: 'tr',
  poller: Ember.inject.service(),
  store: Ember.inject.service(),
  currentUser: Ember.inject.service('current-user'),
  isChecked: false,

  init() {
    this._super(...arguments);

    this.set('truncatedId', String(this.get('job').id).substr(0,5));
  },

  didInsertElement() {
    var store = this.get('store');
    var currentUserId = this.get('currentUser').id;
    this.get('poller').startPolling(function() {
      store.query('job', { user_id: currentUserId });
    });
  },

  didUpdateAttrs(){
  },

  didDestroyElement() {
    this.get('poller').stopPolling();
  },

  actions: {
    togglePublic(){
      this.toggleProperty('job.public')
      this.get('job').save();
    },
    checked(jobId){ this.get('wasChecked')(jobId, event.currentTarget.checked); },
    hasCompleted() {
      this.get('poller').stopPolling();
    },
    deleteWorkflow(workflow){
      var confirmText = `Delete workflow ${workflow.get('name')} ?`;
      if(confirm(confirmText)){ workflow.destroyRecord(); }
    },
  },
});
