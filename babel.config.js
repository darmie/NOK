module.exports = function(api) {
  api.cache(true);
  return {
    presets: ['babel-preset-expo'],
    // plugins: ["const-enum", "@babel/plugin-transform-typescript", ["@babel/plugin-proposal-object-rest-spread", { "loose": true, "useBuiltIns": true }]]
  };
};
