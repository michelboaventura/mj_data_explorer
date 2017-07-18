import Ember from 'ember';

export default Ember.Route.extend({
  model(params){
    return this.store.findRecord('job', params.id);
  },
  setupController(controller, model) {
    var resultsTypes = [
      { id: 'search-tool', text: 'Busca', image: 'search' },
      { id: 'wordtree-diagram', text: 'Árvore de Palavras', image: 'tree' },
      { id: 'graph-canvas', text: 'Grafo de Co-ocorrência', image: 'occurence' },
      { id: 'graph-canvas-full', text: 'Grafo de Co-ocorrência - Todos os dados', image: 'occurence' },
      { id: 'part-item', text: 'Itens-Participantes', image: 'participants' },
      { id: 'sentiment-analysis', text: 'Análise de Sentimentos', image: 'sentiment'},
      { id: 'correlation-matrix', text: 'Matriz de Correlação', image: 'correlation'},
      { id: 'topicos-vis', text: 'Tópicos', image: 'topics' },
    ];

    controller.set('resultsTypes', resultsTypes);
    this._super(controller, model);
  },
});
