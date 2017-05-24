module.exports = {
  root: true,
  parserOptions: {
    ecmaVersion: 2017,
    sourceType: 'module'
  },
  extends: 'eslint:recommended',
  env: {
    browser: true
  },
  rules: {
  },
  "globals": {
    "$": true,
    "Ember": true,
    "d3": true,
    "gViz": true
  }
};